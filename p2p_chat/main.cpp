#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDebug>
#include <QCoreApplication>
#include <iostream>
#include <string>

class P2PChat : public QObject {
    Q_OBJECT

public:
    P2PChat() {
        // Инициализация сокета
        udpSocket = new QUdpSocket(this);
        connect(udpSocket, &QUdpSocket::readyRead, this, &P2PChat::readPendingDatagrams);

        // Привязка сокета
        bool success = udpSocket->bind(QHostAddress::Any, 12345);
        if (!success) {
            qDebug() << "Не удалось привязать UDP сокет.";
            return;
        }

        // Отправка broadcasting сообщения для обнаружения устройств
        QByteArray discoveryMessage = "DISCOVER_P2P_CHAT";
        udpSocket->writeDatagram(discoveryMessage, QHostAddress::Broadcast, 12345);
    }

    void sendMessage(const QString &message) {
        QByteArray data = message.toUtf8();
        for (const QHostAddress &address : knownAddresses) {
            udpSocket->writeDatagram(data, address, 12345);
        }
        qDebug() << "Отправлено сообщение:" << message;
    }

private slots:
    void readPendingDatagrams() {
        while (udpSocket->hasPendingDatagrams()) {
            QNetworkDatagram datagram = udpSocket->receiveDatagram();
            processDatagram(datagram);
        }
    }

private:
    QUdpSocket *udpSocket;
    QList<QHostAddress> knownAddresses;

    void processDatagram(QNetworkDatagram &datagram) {
        QByteArray data = datagram.data();

        // Обработка broadcasting сообщения
        if (data == "DISCOVER_P2P_CHAT") {
            QHostAddress senderAddress = datagram.senderAddress();
            knownAddresses.append(senderAddress);
            qDebug() << "Обнаружен участник чата:" << senderAddress.toString();
        } else {
            // Обработка обычного сообщения
            QString message = QString::fromUtf8(data);
            qDebug() << "Получено сообщение:" << message;
        }
    }
};

#include "main.moc"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    P2PChat chat;

    while (true) {
        std::string input;
        std::cout << "Введите сообщение (или 'exit' для выхода): ";
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        }

        chat.sendMessage(QString::fromStdString(input));
    }

    return 0;
}
