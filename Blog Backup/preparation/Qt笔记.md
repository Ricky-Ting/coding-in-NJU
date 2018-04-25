# Qt笔记

## Qt简介

Qt是一个著名的C++应用程序框架。

1. API映射
2. API模拟
3. GUI模拟

## 信号槽

```
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton button("Quit");
    QObject::connect(&button, &QPushButton::clicked, &QApplication::quit);
    button.show();

    return app.exec();
}
```

QObject::connect()有五个重载

```
connect(sender,   signal,
        receiver, slot);
```