#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 500), "Bouncing balls!");
    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Blue);
    circle.setOrigin(50, 50);
    circle.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    sf::CircleShape circle2(50.f);
    circle2.setFillColor(sf::Color::Yellow);
    circle2.setOrigin(50, 50);
    circle2.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    float MoveSpeed = 0.4;
    bool Xright = false;
    bool Ybottom = false;
    float Xstep = -1;
    float Ystep = -1;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float x1x2 = circle.getPosition().x - circle2.getPosition().x;
        float y1y2 = circle.getPosition().y - circle2.getPosition().y;
        float sum = pow(x1x2,2) + pow(y1y2,2);
        float BallDistance = sqrt(sum);

        if (BallDistance < 100){
            circle.setFillColor(sf::Color::Green);
            circle2.setFillColor(sf::Color::Green);
        }
        else {
            circle.setFillColor(sf::Color::Blue);
            circle2.setFillColor(sf::Color::Yellow);
        }


        if (Xright == false) {
            circle.setPosition(circle.getPosition().x + MoveSpeed, circle.getPosition().y);
            if (circle.getPosition().x + 50 >= window.getSize().x)
                Xright = true;
        }

        else if (Xright == true) {
            circle.setPosition(circle.getPosition().x - MoveSpeed, circle.getPosition().y);
            if (circle.getPosition().x - 50 < 0)
                Xright = false;
        }

        if (Ybottom == false) {
            circle.setPosition(circle.getPosition().x, circle.getPosition().y + MoveSpeed);
            if (circle.getPosition().y + 50 >= window.getSize().y)
                Ybottom = true;
        }

        else if (Ybottom == true) {
            circle.setPosition(circle.getPosition().x, circle.getPosition().y - MoveSpeed);
            if (circle.getPosition().y - 50 < 0)
                Ybottom = false;
        }

        if (circle2.getPosition().x - 50 < 0)
            Xstep = 1;
        else if (circle2.getPosition().x + 50 > window.getSize().x )
            Xstep = -1;

        if (circle2.getPosition().y - 50 < 0)
            Ystep = 1;
        else if (circle2.getPosition().y + 50 > window.getSize().y )
            Ystep = -1;

        

        circle2.move(Xstep, Ystep);
        window.clear(sf::Color(135, 206, 235));
        window.draw(circle2);
        window.draw(circle);
        window.display();


    }

    return 0;
}