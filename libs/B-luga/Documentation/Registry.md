# Registry Class

The `Registry` class serves as a centralized storage and management system for all entities and their components in an ECS (Entity Component System). This class also manages layers for rendering order and allows for event callbacks tied to specific game events.

## Enumerations

### LayerType

Defines the type of layers available for entities.

- `BACKLAYER`
- `FRONTLAYER`
- `DEFAULTLAYER`

### BackLayers

Defines the ordering of back layers.

- `BACK = 0`
- `BACKMAX`

### FrontLayers

Defines the ordering of front layers.

- `FRONT = 0`
- `FRONTMAX`

### Events

Defines various events that can trigger callbacks.

- `REMOVE_ENTITY`
- `TAKE_DAMAGE`
- `CLEAR`
- `ENTITY_DEATH`
- `START_LOOP`
- `END_LOOP`
- `BEFORE_LOOP`
- `AFTER_LOOP`

## Member Functions

### `static Registry &getInstance()`

Singleton access to the Registry instance.

### `template <class Component> components<Component> getComponents()`

Gets a reference to the sparse array holding components of the type specified by the template parameter.

### `std::size_t addEntity()`

Adds an entity to the registry and returns its ID.

### `void removeEntity(std::size_t id)`

Removes an entity and its components from the registry using the provided ID.

### `void removeEntitiesToRemove()`

Removes all entities that have been marked for removal.

### `void addToRemove(std::size_t id)`

Marks an entity to be removed later.

### `void clear()`

Clears all entities, components, and internal data structures.

### `std::vector<std::size_t> getEntitiesByComponents(std::vector<std::type_index> types)`

Returns a list of entities that have all the components of the provided types.

### `std::vector<std::size_t> getEntitiesWithOneOfComponents(std::vector<std::type_index> types)`

Returns a list of entities that have at least one of the components of the provided types.

### `void setToBackLayers(std::size_t id, BackLayers layer)`

Assigns an entity to a specified back layer.

### `void setToDefaultLayer(std::size_t id)`

Assigns an entity to the default layer.

### `void setToFrontLayers(std::size_t id, FrontLayers layer)`

Assigns an entity to a specified front layer.

### `std::vector<std::vector<std::size_t>> getBackLayers()`

Returns all back layers.

### `std::vector<std::size_t> getDefaultLayer()`

Returns the default layer.

### `std::vector<std::vector<std::size_t>> getFrontLayers()`

Returns all front layers.

### `void addAllie(std::size_t typeId, std::type_index type)`

Adds an ally type to the specified entity type ID.

### `void clearAllies(std::size_t typeId)`

Clears allies for the specified entity type ID.

### `void clearAllies()`

Clears all ally relationships.

### `bool checkAllies(std::size_t fstId, std::size_t scdId)`

Checks if two entities are allies based on their components.

### `void addEventCallback(Events event, std::function<void(std::size_t)> callback)`

Adds a callback function for the specified event.

### `void callback(Events event, std::size_t id)`

Triggers event callbacks for a specific entity.

### `void callback(Events event)`

Triggers event callbacks without an entity context.

### `Clock &getClock()`

Returns a reference to the clock instance.

## Private Member Functions

### `void initLayers(bool back)`

Initializes the layer data structures.

### `void removeFromDefaultLayer(std::size_t id)`

Removes an entity from the default layer.

### `std::vector<std::size_t> getExistings(std::type_index type)`

Gets a list of existing entities with a component of the specified type.

### `template <typename Component> void checkAddSparseArray()`

Ensures that a sparse array exists for the specified component type.

### `template <typename Component> void addComponentPlace()`

Adds a place for a new component of the specified type.

### `template <typename Component> void removeComponent(std::size_t id)`

Removes the component of the specified type associated with an entity ID.

### `template <typename Component> std::vector<std::size_t> getExistingsId()`

Returns existing entity IDs for the specified component type.

## Private Member Variables

- `_clock`: An instance of a `Clock` class to track time.
- `_entitiesNb`: The number of entities in the registry.
- `_backLayers`: A list of back layers.
- `_defaultLayer`: The default layer for entities.
