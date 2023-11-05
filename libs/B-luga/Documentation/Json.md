# Json Class Documentation

## Overview
The `Json` class is a singleton class designed to manage JSON data from various files. It provides methods to register JSON files, retrieve data based on keys and IDs, and manipulate JSON objects.

## Singleton Design Pattern
The `Json` class is implemented as a singleton, ensuring that only one instance of the class is created and accessible throughout the application.

### getInstance
```cpp
static Json &getInstance()
```
Returns a reference to the singleton `Json` instance.

## JSON File Registration
### registerJsonFile
```cpp
void registerJsonFile(const std::string &path)
```
Loads and registers a JSON file given its file path.

## JSON Retrieval Methods
### getJsonObjectById
```cpp
template <typename T>
nlohmann::json getJsonObjectById(const std::string &type, const T &id, const std::string &arrayName)
```
Retrieves a JSON object from an array within the registered JSON data based on its `id`.

### getDataByJsonType
There are several overloads of this method to retrieve JSON data based on the type:

- For retrieving a JSON object given a data type and an index:
```cpp
template <typename T>
T getDataByJsonType(const std::string &dataType, const std::string &index)
```
- For retrieving a JSON object given just a data type:
```cpp
nlohmann::json getDataByJsonType(const std::string &dataType)
```

### findKeyRecursively
```cpp
void findKeyRecursively(
    const nlohmann::json &data,
    const std::string &key,
    std::vector<std::string> &results)
```
Searches for a key recursively in the given JSON data and stores the results in a vector.

### getDatasByKey
```cpp
std::vector<std::string> getDatasByKey(std::vector<std::string> dataTypes, const std::string &key)
```
Retrieves all data associated with a specific key across different data types.

### getDatasFromList
There are multiple methods to extract data from a list, given different parameters:
- With a list and an index:
```cpp
std::vector<nlohmann::json> getDatasFromList(const nlohmann::json &list, const std::string &index)
```
- With a list only:
```cpp
std::vector<nlohmann::json> getDatasFromList(const nlohmann::json &list)
```

## Data Validation Method
### isDataExist
```cpp
static bool isDataExist(nlohmann::basic_json<> jsonData, const std::string &index)
```
Checks if a given key exists in the JSON data.

## Advanced Data Retrieval Methods
### getDatasByJsonType
```cpp
std::vector<nlohmann::json>
getDatasByJsonType(const std::string &dataType, const std::vector<std::string> &indexes)
```
Retrieves a vector of JSON objects based on a data type and a sequence of indexes.

### getDataFromJson
```cpp
template <typename T>
T getDataFromJson(nlohmann::json jsonData, const std::string &index)
```
Retrieves data of a specified type from a JSON object given a key.

### getObjectsIdInArray
```cpp
template <typename T>
std::vector<T> getObjectsIdInArray(const std::string &dataType, const std::string &arrayName)
```
Retrieves a vector of IDs from an array of JSON objects.

### getDataByVector
Retrieves data by navigating through a series of indexes in nested JSON objects.
- For getting JSON data:
```cpp
nlohmann::json getDataByVector(const std::string &dataType, const std::vector<std::string> &indexes)
```
- Template version for different data types:
```cpp
template <typename T>
T getDataByVector(const std::string &dataType, const std::vector<std::string> &indexes)
```

## Private Methods
### Constructor and Destructor
The constructor and destructor are private to control the instantiation of the singleton class.

### getDatasFromList (Overloaded Private Method)
```cpp
std::vector<nlohmann::json> &
getDatasFromList(std::vector<nlohmann::json> &datas, nlohmann::json &listData, const std::string &key)
```
Aids in data extraction from a list for internal processing.

### loadJsonData
```cpp
static nlohmann::json loadJsonData(const std::string &path)
```
Loads JSON data from a file.

## Data Members
### _jsonDatas
```cpp
std::unordered_map<std::string, nlohmann::json> _jsonDatas;
```
Stores JSON data associated with their resolved file paths.

## Dependencies
- `nlohmann::json`: