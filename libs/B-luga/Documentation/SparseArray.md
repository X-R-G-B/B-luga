# SparseArray Class Documentation

## Overview

`SparseArray` is a template class that provides a data structure for efficient storage and retrieval of sparse data. This is particularly useful when there is a need to store elements at large indexes without allocating memory for unused indexes. It internally manages a dense array for the actual data and a sparse array to keep track of the occupied indices.

## Template Parameter

- `Component`: The type of elements stored in the `SparseArray`.

## Public Methods

### `void add()`

Adds a placeholder for a new component to the sparse array, expanding its size.

### `void insertBack(Component &value)`

Inserts a new component at the back of the sparse array.

#### Parameters

- `value`: Reference to the component to be inserted.

### `void insert(size_t id, Component &value)`

Inserts a component at the specified ID in the sparse array.

#### Parameters

- `id`: The ID where the component should be inserted.
- `value`: Reference to the component to be inserted.

### `void erase(std::size_t id)`

Erases the component associated with the specified ID from the sparse array.

#### Parameters

- `id`: The ID of the component to be erased.

### `Component &operator[](size_t id)`

Provides access to the component by ID.

#### Parameters

- `id`: The ID of the component to access.

#### Returns

- A reference to the component at the given ID.

### `Component &back()`

Returns the last component in the dense array.

#### Returns

- A reference to the last component.

### `typename std::vector<Component>::iterator begin()`

Returns an iterator pointing to the beginning of the dense array.

#### Returns

- An iterator to the beginning of the dense array.

### `typename std::vector<Component>::iterator end()`

Returns an iterator pointing to the end of the dense array.

#### Returns

- An iterator to the end of the dense array.

### `bool exist(std::size_t id)`

Checks if a component exists at the specified ID.

#### Parameters

- `id`: The ID to check for a component's existence.

#### Returns

- `true` if a component exists at the ID, `false` otherwise.

### `std::vector<std::size_t> getExistingsId()`

Gets a vector of all existing IDs in the sparse array.

#### Returns

- A vector of existing IDs.

### `void clear()`

Clears the sparse array, removing all components.

## Private Methods

Details of private methods are generally not included in public documentation, as they are meant for internal use only.

## Example Usage

```cpp
SparseArray<int> mySparseArray;

// Add a new element and insert at back
mySparseArray.add();
int myValue = 10;
mySparseArray.insertBack(myValue);

// Insert element at specific ID
int anotherValue = 20;
mySparseArray.insert(5, anotherValue);

// Access element by ID
int value = mySparseArray[5];

// Erase element at ID
mySparseArray.erase(5);

// Check if an ID exists
bool exists = mySparseArray.exist(10);

// Get the last element
int lastValue = mySparseArray.back();

// Clear the array
mySparseArray.clear();