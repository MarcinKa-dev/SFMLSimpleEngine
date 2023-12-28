# Simple 2D Game Engine using SFML
## Overview
This project is a simple 2D game engine built on the SFML library. It's designed for educational purposes to demonstrate programming skills and create a basic yet flexible game engine.

# Features
- **Graphics:** Rendering of 2D objects using SFML.
- **Input Handling:** Basic input management for keyboard and mouse.
- **Resource Management:** Loading and managing textures, sounds, and other resources.
- **Entity System:** Simple entity system to manage game objects.
- **Collision Detection:** Basic collision detection functionality.
- **Game States:** Implementation of different game states (e.g., menu, playing).

# Getting Started

### Prerequisites:

- Install SFML. You can download it [here](https://www.sfml-dev.org/download.php).
### Clone the Repository:

```bash
Copy code
git clone https://github.com/MarcinKa-dev/SFMLSimpleEngine.git
```
### Build the Project:

- Open the project in your preferred IDE or build using CMake.

### Run the Game:

- Execute the compiled binary.
## Usage
- **Adding Entities:**

    - Extend the Entity class or create new classes implementing IEntity for game objects.

- **Loading Textures:**

    - Use the TextureManager to load and manage textures.

- **Handling Input:**

    - Utilize the InputManager to handle keyboard and mouse input.

- **Managing Game States:**

    - Create new classes implementing IGameState for different game states.
## Contributing
Contributions are welcome! If you find any issues or have suggestions for improvements, feel free to create an issue or submit a pull request.

## License
This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments
- Inspired by the SFML library.
