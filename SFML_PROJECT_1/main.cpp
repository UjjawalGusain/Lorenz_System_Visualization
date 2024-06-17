#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

const float SCALE_FACTOR = 10.3f;

int width, height;
float sigma = 10, rho = 28, beta = 8 / 3.0f;

// Function to map 3D coordinates to screen coordinates
Vector2f mapToScreenCoordinates(float x, float y) {
    return Vector2f(x * SCALE_FACTOR + width / 2.0f, y * SCALE_FACTOR + height / 2.0f);
}

// Function to update the Lorenz system state
void updateLorenz(float& x, float& y, float& z, float& dx, float& dy, float& dz, float dt) {
    dx = sigma * (y - x) * dt;
    dy = (x * (rho - z) - y) * dt;
    dz = (x * y - beta * z) * dt;
    x += dx;
    y += dy;
    z += dz;

    // Limiting range
    x = max(min(x, (float)width), (float)-width);
    y = max(min(y, (float)height), (float)-height);
}

// Function to create pixels on the screen
void createPixel(float& x, float& y, float& z, float& dx, float& dy, float& dz, float dt, Image& image, bool red) {
    updateLorenz(x, y, z, dx, dy, dz, dt);

    Vector2f screenCoords = mapToScreenCoordinates(x, y);

    if (screenCoords.x >= 0 && screenCoords.x < width && screenCoords.y >= 0 && screenCoords.y < height) {
        image.setPixel((int)screenCoords.x, (int)screenCoords.y, red ? Color::Red : Color::Blue);
    }
}

int main() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    width = desktop.width;
    height = desktop.height;
    cout << "Screen dimensions: " << width << " x " << height << endl;
    RenderWindow window(VideoMode(width, height), "Lorenz Attractor");

    Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cerr << "Failed to load font!" << endl;
        return 1;
    }

    // Text for title
    Text titleText;
    titleText.setFont(font);
    titleText.setString("Lorenz system Chaos Theory Visualization");
    titleText.setCharacterSize(30);
    titleText.setFillColor(Color::White);
    titleText.setStyle(Text::Bold);
    titleText.setPosition(width / 2.0f - 250, 50);

    Text press_enter;
    press_enter.setFont(font);
    press_enter.setString("Press enter to start");
    press_enter.setCharacterSize(60);
    press_enter.setFillColor(Color::White);
    press_enter.setStyle(Text::Bold);
    press_enter.setPosition(width / 2.0f - 250, height / 2.0f - 30);

    Image image;
    image.create(width, height, Color::Black);

    // Initial conditions
    float x_1 = 0.1f, y_1 = 0.0f, z_1 = 0.0f;
    float x_2 = 0.2f, y_2 = 0.0f, z_2 = 0.0f;
    float dx_1, dy_1, dz_1;
    float dx_2, dy_2, dz_2;
    float dt = 0.01f;

    bool animationStarted = false; // Flag to track animation start

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            // Check for Enter key press to start animation
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Return) {
                animationStarted = true;
            }
        }

        window.clear();

        // Check if animation has started
        if (animationStarted) {
            // Create red and blue pixels
            createPixel(x_1, y_1, z_1, dx_1, dy_1, dz_1, dt, image, true);
            createPixel(x_2, y_2, z_2, dx_2, dy_2, dz_2, dt, image, false);
        }
        // Update texture and draw
        Texture texture;
        texture.loadFromImage(image);
        Sprite sprite(texture);
        window.draw(sprite);
        window.draw(titleText);
        if (!animationStarted)
            window.draw(press_enter);

        window.display();
    }

    return 0;
}
