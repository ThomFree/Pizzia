/*
** EPITECH PROJECT, 2019
** CPP_zia_github
** File description:
** IMapContainer
*/

#include <string>

#pragma once

namespace Pizzia {

/*
** This Interface allow you to make your own container that your module will use
** All the data are stored in an unordered_map<string, string>
*/
class IMapContainer {
	public:
		IMapContainer() = default;
		virtual ~IMapContainer() noexcept = default;
		IMapContainer &operator=(const IMapContainer &) = delete;

	public:
		/*
		** Create an element in the map only if it doesn't exist and return true
		** Otherwise it returns false
		*/
		virtual bool create(const std::string &key, const std::string &value) = 0;
		virtual bool create(const std::string &key, int value) = 0;
		virtual bool create(const std::string &key, bool value) = 0;
		virtual bool create(const std::string &key, float value) = 0;

		/*
		** Those functions put in the container in any case
		*/
		virtual void put(const std::string &key, const std::string &value) = 0;
		virtual void put(const std::string &key, int value) = 0;
		virtual void put(const std::string &key, bool value) = 0;
		virtual void put(const std::string &key, float value) = 0;

		/*
		** Simple getters that convert the string into the type you choose
		*/
		virtual std::string getString(const std::string &key) const = 0;
		virtual int getInt(const std::string &key) const = 0;
		virtual bool getBool(const std::string &key) const = 0;
		virtual float getFloat(const std::string &key) const = 0;

		/*
		** Function to delete an element and below the function return true if the unordered 
		** map contains the element
		*/
		virtual void del(const std::string &key) = 0;
		virtual bool has(const std::string &key) const = 0;

		/*
		** Those functions return iterator on the unordered map
		*/
		virtual std::unordered_map<std::string, std::string>::const_iterator begin() const = 0;
		virtual std::unordered_map<std::string, std::string>::const_iterator end() const = 0;
};

}