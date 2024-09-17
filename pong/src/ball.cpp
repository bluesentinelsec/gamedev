#include "ball.hpp"

namespace game
{
Ball::Ball()
{
    ball.setRadius(ballRadius);
    ballX = 160 / 2 - ballRadius;
    ballY = 144 / 2 - ballRadius;
    ball.setPosition(ballX, ballY);
    ball.setFillColor(ballColor);
    ball.setOutlineColor(ballColor);
}
} // namespace game