#include "paddelwidthWeapon"

WidenPaddleWeapon::WidenPaddleWeapon(Paddle* paddle, int widthIncrease, int durationInSeconds)
    : paddle(paddle), widthIncrease(widthIncrease), durationInSeconds(durationInSeconds)
{
    originalWidth = paddle->boundingRect().width();
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &WidenPaddleWeapon::deactivate);
}

void WidenPaddleWeapon::activate()
{
    paddle->setRect(0, 0, originalWidth + widthIncrease, paddle->boundingRect().height());
    timer->start(durationInSeconds * 1000);
}

void WidenPaddleWeapon::deactivate()
{
    paddle->setRect(0, 0, originalWidth, paddle->boundingRect().height());
    timer->stop();
}

bool WidenPaddleWeapon::isActive() const
{
    return timer->isActive();
}
