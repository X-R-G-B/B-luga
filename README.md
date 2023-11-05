# ECS Documentation

## Table of Contents

- [Introduction](#introduction)
- [Creating a Plugin](#creating-a-plugin)
    - [Defining IPlugin](#defining-iplugin)
    - [Implementing IPlugin](#implementing-iplugin)
    - [Adding a Plugin via PluginHandler](#adding-a-plugin-via-pluginhandler)
- [Using exemple](#using-exemple)

## Introduction

This ECS (Entity Component System) is designed as a robust framework for building complex simulations and games. It uses a registry system implemented as a singleton that contains sparse arrays with dense data storage, ensuring efficient and fast component access patterns.

Alongside the core ECS features, this system is equipped with a JSON parsing overlay, facilitating easy data manipulation and storage in a structured format. A SceneManager is present to manage different scenes or states within the application, providing seamless transitions and organized state handling.

The ECS also includes a logger utility, which developers can use to track events, errors, and other significant occurrences throughout the application lifecycle, aiding in debugging and monitoring.

Lastly, a clock manager is integrated into the system to handle timing, allowing for consistent updates across different systems, essential for synchronization in simulations and real-time applications.

## Creating a Plugin

Developers can extend the functionality of the ECS by creating plugins. A plugin is a concrete implementation of the `IPlugin` interface, which initializes specific systems and adds them to the global system management.

### Defining IPlugin

The `IPlugin` interface is defined as follows:

```cpp
class IPlugin {
public:
    virtual ~IPlugin() = default;
    virtual void initPlugin() = 0;
    virtual std::vector<std::function<void(std::size_t, std::size_t)>> getSystems() = 0;
};
```

### Implementing IPlugin

To create a new plugin, one should inherit from `IPlugin` and implement the `initPlugin` and `getSystems` methods. Here is an example implementation:

```cpp
#include <vector>
#include <functional>

class ExamplePlugin : public IPlugin {
public:
    void initPlugin() override {
        // Specific initialization for this plugin
    }

    std::vector<std::function<void(std::size_t, std::size_t)>> getSystems() override {
        // Return the list of systems as functions
        return {
            fstSystem,
            scdSystem
        };
    }
};
```

### Adding a Plugin via PluginHandler

Once the plugin is implemented, it can be added to the ECS using the `PluginHandler` class. Here's how you might add your plugin:

```cpp
#include "PluginHandler.h"
#include "ExamplePlugin.h"

int main() {
    ExamplePlugin myPlugin;

    enum SystemManagers { MENU, GAME, PLUGIN};
    PluginHandler::addNewPlugin(myPlugin, static_cast<std::size_t>(SystemManagers::PLUGIN));

    // Proceed with the rest of the program
}
```

Using `addNewPlugin`, the plugin is initialized and the systems it provides are added to the appropriate system manager. If a `managerId` is provided, the system will be added to a specific system manager.

## Using exemple

This is a game using this ecs: https://github.com/X-R-G-B/R-dash
