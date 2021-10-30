#include <iostream>
#include <fstream>
#include "priorityqueue.h"
#include "json.hpp"

int main(int argc, char** argv) {

    std::ifstream file;
    file.open(argv[1]);
    nlohmann::json jsonObject;
    if(file.is_open()){
        file >> jsonObject;
    }
    file.close();

    int maxHeapSize = jsonObject["metadata"]["maxHeapSize"];        //set the maxheapsize
    int numOperations = jsonObject["metadata"]["numOperations"];    //set the numoperations
    PriorityQueue json_data(maxHeapSize);                           //create a priorityqueue with the json object
    for (auto itr = jsonObject.begin(); itr != (jsonObject.end()); itr++)
    {
        if(itr.value()["operation"] == "insert" ) {
            //insert key here
            double key = itr.value()["key"];
            json_data.insert(key);
        }
        else if(itr.value()["operation"] == "removeMin"){
            //removeMin if command is to remove it
            json_data.removeMin();
        }
    }
    

    nlohmann::json resultant_data_object = json_data.JSON();
    resultant_data_object["metadata"]["numOperations"] = numOperations;
    resultant_data_object["metadata"]["maxHeapSize"] = maxHeapSize;
    std::cout << resultant_data_object.dump(2) << std::endl;

}
