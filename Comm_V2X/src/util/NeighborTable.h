/*
 * NeighborTable.h
 *
 *  Created on: Jun 26, 2016
 *      Author: pannu
 */

#ifndef NEIGHBORTABLE_H_
#define NEIGHBORTABLE_H_

//#include <omnetpp.h>
#include "../src/veins/base/utils/Coord.h"
#include <string>
#include <vector>

using namespace std;

struct NodeInfo {
    int id;
    simtime_t timestamp;
    veins::Coord coord;

    // add more information, if necessary.
};


class NeighborTable {
public:
    NeighborTable(int myId);
    virtual ~NeighborTable();

    /** @brief Add information about node in the neighbor table */
    void addNode(int id, NodeInfo* node);

    /** @brief Removes the outdated information (older than timelimit) from the neighbor table
     *  @param timelimit The time older than which an entry for the node is deleted
     */
    void purgeNodes(double timelimit);

    /** @brief Delete all entries in the neighbor table */
    void clearTable();

    /** @brief Delete a single node from the neighbor table */
    void deleteNode(int id);

    int getNeighborCount();

    vector<int> getNeighborIds();

    /** @brief Prints the content from the neighbor table */
    void printTable(const char* reason);

    /** @brief Helper function to print the table */
    string center(const string str, int width);

private:
    vector<NodeInfo*> neighborNodes;
    int myId;
};

#endif /* NEIGHBORTABLE_H_ */
