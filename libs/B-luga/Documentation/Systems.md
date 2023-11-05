# SystemManagersDirector

## SystemManagersDirector Overview

`SystemManagersDirector` is a central hub for managing various `SystemManager` instances within the ECS framework. Each `SystemManager` is responsible for updating the systems associated with a particular state, scene, or functionality of the application, such as menus, gameplay, plugins, etc.

## Implementation Details

### SystemManagersDirector

```cpp
namespace Systems {
    class SystemManagersDirector {
        public:
            // Singleton instance retrieval
            static SystemManagersDirector &getInstance()

            // Retrieve a specific SystemManager by ID
            SystemManager &getSystemManager(std::size_t id)

            // Add a new SystemManager
            void addSystemManager(std::size_t id, std::vector<std::function<void(std::size_t, std::size_t)>> systems)

            // Remove a SystemManager
            void removeSystemManager(std::size_t id)

            // Reset state changes in all SystemManagers
            void resetChanges()

            std::mutex mutex;

        private:
            std::map<std::size_t, SystemManager> _systemManagers;
            SystemManagersDirector() = default;
    };
} // namespace Systems
```

### Usage

#### Enums for SystemManagers

It's recommended to use enums to represent the IDs of different `SystemManager` instances for readability and maintainability.

```cpp
enum SystemManagers { MENU, GAME, PLUGIN };
```

#### Adding SystemManagers

You can add a new `SystemManager` like so:

```cpp
auto& systemManagersDirector = Systems::SystemManagersDirector::getInstance();
std::vector<std::function<void(std::size_t, std::size_t)>> systemsList = /* ... */;
systemManagersDirector.addSystemManager(systemsList, SystemManagers::MENU);
```

### SceneManager Integration

`SceneManager` interacts with `SystemManagersDirector` by referring to the same `SystemManagers` enum IDs when adding scenes or setting up multiple scenes.

#### Modifying Scenes

```cpp
auto& sceneManager = Scene::SceneManager::getInstance();

// Adding a single scene
sceneManager.addScene({SystemManagers::MENU});

// Setting multiple scenes at once
sceneManager.setScenes({{SystemManagers::MENU}, {SystemManagers::GAME, SystemManagers::PLUGIN}});
```

This integration ensures consistency and eases the management of which systems are active in a given scene.

## Conclusion

With the `SystemManagersDirector`, you have a centralized and organized way to manage different sets of systems associated with various parts of your application. By using enum IDs, the code remains clean and the mapping between scenes and their corresponding systems is intuitive.

The `SceneManager`, working closely with the `SystemManagersDirector`, offers a straightforward interface for transitioning between scenes, which can encompass different gameplay states, menus, and plugins, effectively separating concerns and promoting modular design in your application.