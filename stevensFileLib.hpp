/**
 * @file stevensFileLib.hpp
 * @author your name (jeff@bucephalusstudios.com)
 * @brief A cool library for working with files
 * @version 0.1
 * @date 2024-02-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<unordered_map>
#include<fstream>


namespace stevensFileLib
{
    /**
     * @brief Given a filepath, opens a file and returns the input file stream object associated with the opened file.
     *        Performs checks during opening to make sure that the file exists.
     * 
     * @return std::ifstream 
     */
    std::ifstream openFile( const std::string & filePath )
    {
        std::ifstream file(filePath);
        if (!file.is_open())
        {
            //Error if we could not find the file
            throw std::invalid_argument("Error, could not find file: " + filePath);
        }
        return file;
    }


    /**
     * @brief Given a file, load its contents line-by-line into a vector of ints.
     * 
     * @param filePath - The string path to the file that we want to load into a vector.
     * @param settings - An ma of string keys and values of vectors of strings containing settings
     *                   to further specify how you want to load the file into the vector. 
     * @param skipEmptyLines - If true, skip lines that are empty.
     */
    std::vector<int> loadFileIntoVectorOfInts(  const std::string & filePath,
                                                const std::unordered_map< std::string, std::vector<std::string> > settings = {},
                                                const char separator = '\n',
                                                const bool skipEmptyLines = true)
    {

        //Open the file with safety checks
        std::ifstream file = stevensFileLib::openFile(filePath);

        //Declare the vector that we'll be pushing our integer data back into from the file
        std::vector<int> vec;
        //As well as the variable that holds the integer data
        int data;
        //Use the stream operator to take each line of the file and load it into vec
        while(file >> data)
        {
            vec.push_back(data);
        }

        //Complete the cleanup by closing the file
        file.close();

        //Return the vector, now full of content from the file
        return vec;
    }
}