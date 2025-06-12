/*
 * NeighborTable.cpp
 *
 *  Created on: Jun 26, 2016
 *      Author: pannu
 */

#include "NeighborTable.h"

using namespace std;

NeighborTable::NeighborTable(int myId) {
    this->myId = myId;
}

NeighborTable::~NeighborTable() {
}

void NeighborTable::addNode(int id, NodeInfo* node) {
    if(neighborNodes.size() == 0) {
        neighborNodes.push_back(node);
        printTable("addNode");
        return;
    }
    bool present = false;
    for(uint idx = 0; idx < neighborNodes.size(); idx++) {
        if(neighborNodes[idx]->id == node->id) {
            present = true;
            neighborNodes.erase(neighborNodes.begin() + idx);
            break;
        }
    }
    neighborNodes.push_back(node);
    cout << myId << ">> addNode: " << id<< " at time: " << node->timestamp << ", was present ? " << present << endl;
    printTable("addNode");
}

void NeighborTable::deleteNode(int id) {
    neighborNodes.erase(neighborNodes.begin() + id);
}

void NeighborTable::clearTable() {
    neighborNodes.erase(neighborNodes.begin(), neighborNodes.end());
}

int NeighborTable::getNeighborCount() {
    return neighborNodes.size();
}

vector<int> NeighborTable::getNeighborIds() {
    vector<int> res;
    for (uint idx = 0; idx < neighborNodes.size(); idx++) {
        res.push_back(neighborNodes[idx]->id);
    }
    return res;
}

void NeighborTable::purgeNodes(double timelimit) {
    bool anyItemRemoved = false;
    cout << myId << ">> removeStaleNodes>> Table size: " << neighborNodes.size() << endl;
    for (uint idx = 0; idx < neighborNodes.size(); idx++) {
        simtime_t currTime = simTime();
        simtime_t nodeTime = neighborNodes[idx]->timestamp;
        double diff = currTime.dbl() - nodeTime.dbl();
        cout << myId << ">> removeStaleNodes>> CurrTime: "<< currTime << ", nodeTime: " << nodeTime << " and diff: " << diff << endl;
        if (diff > timelimit) {
            cout << myId << ">> removeStaleNodes>> Removing node: " << neighborNodes[idx]->id << endl;
            neighborNodes.erase(neighborNodes.begin() + idx);
            idx--;
            anyItemRemoved = true;
        }
    }
    if(anyItemRemoved)
        printTable("After removeStaleNodes");
}

void NeighborTable::printTable(const char* reason) {
    if (neighborNodes.size() == 0) {
        cout << myId << ">> Empty table : at time : " << simTime() <<", reason : " << reason << endl;
        return;
    }
    std::cout << myId << ">> Table : at time : " << simTime() << " reason : " << reason << endl;
    cout << center("Id",20)       << " | "
         << center("Time",20)     << " | "
         << center("Coords",20) << endl;
    for (uint idx = 0; idx < neighborNodes.size(); idx++) {
        cout << center(to_string(neighborNodes[idx]->id), 20) << " | "
             << center(neighborNodes[idx]->timestamp.str(), 20) << " | " << endl;
             // << center(x.second.coord.info()) << "\n";
    }
    cout << endl;
}


string NeighborTable::center(const string s, int w) {
    stringstream ss, spaces;
    int padding = w - s.size();
    for(int i=0; i<padding/2; ++i)
        spaces << " ";
    ss << spaces.str() << s << spaces.str();
    if(padding>0 && padding%2!=0)
        ss << " ";
    return ss.str();
}
