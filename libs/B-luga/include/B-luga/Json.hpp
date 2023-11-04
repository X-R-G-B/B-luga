/*
** EPITECH PROJECT, 2023
** R-Bus
** File description:
** Json
*/

#pragma once

#include <string>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include "nlohmann/json.hpp"
#include "B-luga/Logger.hpp"
#include "B-luga/PathResolver.hpp"

class Json {
    public:
        static Json &getInstance()
        {
            static auto instance = Json();
            return instance;
        }

        void registerJsonFile(const std::string &path)
        {
            const std::string path_resolved = PathResolver::resolve(path);

            if (_jsonDatas.find(path_resolved) == _jsonDatas.end()) {
                _jsonDatas.insert({path_resolved, loadJsonData(path_resolved)});
            }
        }

        template <typename T>
        nlohmann::json getJsonObjectById(const std::string &type, const T &id, const std::string &arrayName)
        {
            auto objectList = getDataByJsonType(type)[arrayName];

            for (const auto &object : objectList) {
                auto idField = object.find("id");
                if (idField != object.end() && idField->get<T>() == id) {
                    return object;
                }
            }
            Logger::fatal(std::string("(getJsonObject) Key : is not valid for array : " + arrayName));
            throw std::runtime_error("Json error");
        }

        template <typename T>
        T getDataByJsonType(const std::string &dataType, const std::string &index)
        {
            const std::string path_resolved = PathResolver::resolve(dataType);
            nlohmann::json finalData(_jsonDatas[path_resolved]);

            finalData = finalData[index];
            if (finalData == nullptr) {
                Logger::fatal(std::string("(getDataByVector) Key : ") + index + std::string(" is not valid"));
                throw std::runtime_error("Json error");
            }

            return (finalData);
        }

        nlohmann::json getDataByJsonType(const std::string &dataType)
        {
            const std::string path_resolved = PathResolver::resolve(dataType);
            nlohmann::json data(_jsonDatas[path_resolved]);

            return (data);
        }

        nlohmann::basic_json<> getDataByJsonType(const std::string &dataType, const std::string &index)
        {
            const std::string path_resolved = PathResolver::resolve(dataType);
            nlohmann::basic_json<> finalData(_jsonDatas[path_resolved]);

            finalData = finalData[index];
            if (finalData == nullptr) {
                Logger::error(std::string("(getDataByJsonType) Key : ") + index + std::string(" is not valid"));
            }
            return (finalData);
        }

        std::vector<nlohmann::json>
        getDatasFromList(const std::vector<nlohmann::json> &list, const std::string &index)
        {
            std::vector<nlohmann::json> datas;
            std::vector<nlohmann::json> tmp;

            for (const auto &elem : list) {
                if (elem[index] == nullptr) {
                    Logger::fatal(std::string("(getDatasDromList : 2) Key : ") + index + std::string(" is not valid"));
                    throw std::runtime_error("Json error");
                }
                if (elem[index].is_array() == true) {
                    tmp = getDatasFromList(elem[index]);
                    datas.insert(datas.end(), tmp.begin(), tmp.end());
                } else {
                    datas.push_back(elem[index]);
                }
            }
            return (datas);
        }

        std::vector<nlohmann::json> getDatasFromList(const nlohmann::json &list, const std::string &index)
        {
            std::vector<nlohmann::json> datas;

            for (const auto &elem : list) {
                if (elem[index] == nullptr) {
                    Logger::fatal(std::string("(getDatasFromList : 1) Key : ") + index + std::string(" is not valid"));
                    throw std::runtime_error("Json error");
                }
                datas.push_back(elem[index]);
            }
            return (datas);
        }

        std::vector<nlohmann::json> getDatasFromList(const nlohmann::json &list)
        {
            std::vector<nlohmann::json> datas;

            if (list.is_array() == false) {
                Logger::fatal(std::string("(getDatasFromList : 3) Conversion to list is not possible"));
                throw std::runtime_error("Json error");
            }
            for (const auto &elem : list) {
                datas.push_back(elem);
            }
            return (datas);
        }

    static bool isDataExist(nlohmann::basic_json<> jsonData, const std::string &index)
    {
        if (jsonData[index] == nullptr) {
            return (false);
        }
        return (true);
    }

    std::vector<nlohmann::json>
    getDatasByJsonType(const std::string &dataType, const std::vector<std::string> &indexes)
    {
        nlohmann::json finalData = getDataByJsonType(dataType);
        std::vector<nlohmann::json> datas;

        for (const auto &key : indexes) {
            if (finalData.is_array() || !datas.empty()) {
                datas = getDatasFromList(datas, finalData, key);
                continue;
            }
            if (finalData[key] == nullptr) {
                throw std::runtime_error("Json error");
            }
            finalData = finalData[key];
        }
        if (datas.empty()) {
            datas.push_back(finalData);
        }
        return datas;
    }

    template <typename T>
    T getDataFromJson(nlohmann::json jsonData, const std::string &index)
    {
        if (jsonData[index] == nullptr) {
            Logger::fatal(std::string("(getDataByJson<template>) Key : ") + index + std::string(" is not valid"));
            throw std::runtime_error("Json error");
        }
        return jsonData[index].get<T>();
    }

    template <typename T>
    T getDataByVector(const std::string &dataType, const std::vector<std::string> &indexes)
    {
        auto datas = getDataByJsonType(dataType);
        auto begin = indexes.begin();
        std::stringstream s;

        if (indexes.empty()) {
            Logger::fatal(std::string("(getDataByVector<T>): empty list"));
            throw std::runtime_error("Json error");
        }
        for (; begin + 1 != indexes.end(); begin++) {
            if (datas[*begin] == nullptr) {
                s << datas;
                Logger::fatal(std::string("(getDataByVector<T>) Key : '") + *begin + std::string("' is not valid from '") + dataType + std::string("'; in data: ```") + s.str() + std::string("```"));
                throw std::runtime_error("Json error");
            }
            datas = datas[*begin];
        }
        return getDataFromJson<T>(datas, *(indexes.end() - 1));
    }

    nlohmann::json getDataByVector(const std::string &dataType, const std::vector<std::string> &indexes)
    {
        return getDataByVector<nlohmann::json>(dataType, indexes);
    }

private:
    Json()  = default;
    ~Json() = default;

    std::vector<nlohmann::json> &
    getDatasFromList(std::vector<nlohmann::json> &datas, nlohmann::json &listData, const std::string &key)
    {
        if (datas.empty()) {
            datas = getDatasFromList(listData);
            datas = getDatasFromList(datas, key);
        } else {
            datas = getDatasFromList(datas, key);
        }
        return (datas);
    }

    static nlohmann::json loadJsonData(const std::string &path)
    {
        std::ifstream fileData(path);
        std::ostringstream input;
        nlohmann::json jsonData = {};

        if (fileData.is_open()) {
            input << fileData.rdbuf();
            if (nlohmann::json::accept(input.str())) {
                jsonData = nlohmann::json::parse(input.str());
                return jsonData;
            }
        }
        return jsonData;
    }

    std::unordered_map<std::string, nlohmann::json> _jsonDatas;
};
