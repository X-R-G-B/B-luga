# SceneManager Documentation

## Overview

The SceneManager is a central part of the ECS framework, responsible for managing different scenes within the application. Each scene represents a state or a level of the game/application, encapsulating specific entities, components, and systems.

## Implementation Details

```cpp
namespace Scene {

    enum class ReturnValue { OK = 0, RET_ERROR = 84 };

    class SceneManager {
        public:
            // Singleton instance retrieval
            static SceneManager &getInstance()

            // Main run loop
            int run()

            // Scene change handler
            void changeScene(std::size_t scene)

            // Getter for the current scene
            [[nodiscard]] std::size_t getCurrentScene() const

            // Stops the run loop
            void stop()

            // Sets up multiple scenes
            void setScenes(std::vector<std::vector<std::size_t>> scenes)

            // Adds a single scene
            void addScene(std::vector<std::size_t> scene)

        private:
            // Constructor
            SceneManager() : _currentScene(0), _stop(false) {};

            // Updates systems for the current scene
            void updateSystemManagers(std::vector<std::size_t> &scene)

            // Scene management variables
            std::size_t _currentScene;
            bool _stop;
            std::vector<std::vector<std::size_t>> _scenes;
    };
} // namespace Scene
```

## Usage

### Singleton Instance

The SceneManager is implemented as a singleton, ensuring that there is only one instance of it throughout the application. You can access the instance using:

```cpp
auto& sceneManager = Scene::SceneManager::getInstance();
```

### Running the Scene Manager

To run the scene manager, you simply call the `run` method:

```cpp
int main() {
    auto& sceneManager = Scene::SceneManager::getInstance();
    return sceneManager.run();
}
```

### Set and Change Scenes

See in ./Systems.md

### Stopping the Scene Manager

When you need to stop the scene manager, perhaps when the game is exiting or transitioning to a different state, use the `stop` method:

```cpp
sceneManager.stop();
```

### Retrieving the Current Scene

To get the index of the current scene:

```cpp
auto currentSceneIndex = sceneManager.getCurrentScene();
```

The SceneManager serves as a powerful tool for managing the different phases or levels of your application, ensuring smooth transitions and efficient state management.