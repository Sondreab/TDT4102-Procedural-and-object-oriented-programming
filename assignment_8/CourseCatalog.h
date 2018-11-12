#pragma once
#include <string>
#include <map>


class CourseCatalog {
	private:
		typedef std::map<std::string, std::string> CatalogMap;
		CatalogMap courses;

	public:
		void addCourse();
		void removeCourse();
		void writeToFile(std::string filename);

		friend std::ostream& operator<<(std::ostream& os, const CourseCatalog& rhs);
};

