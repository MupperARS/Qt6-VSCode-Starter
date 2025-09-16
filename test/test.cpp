#include <QtTest>

class Test : public QObject
{
    Q_OBJECT
private slots:
    void testInitialization()
    {
        
    }
};

QTEST_MAIN(Test)
#include "test.moc"