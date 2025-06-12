//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package comm_v2x.application;
import org.car2x.veins.base.modules.IBaseApplLayer;

simple RSUApplication like IBaseApplLayer
{
    parameters:
        @class(RSUApplication);
        int headerLength = default(88bit) @unit("bit"); //header length of the application
        int packetLength = default(1024bit) @unit("bit"); //packet length of the application
        
        bool source = default(false);
        volatile double awarenessInterval = default(1s) @unit("s");
        volatile double emergencyInterval = default(1s) @unit("s");

    gates:
        input lowerLayerIn; // from mac layer
        output lowerLayerOut; // to mac layer
        input lowerControlIn;
        output lowerControlOut;
        
}
