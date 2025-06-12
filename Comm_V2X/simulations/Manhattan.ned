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

package comm_v2x.simulations;

import org.car2x.veins.base.connectionManager.ConnectionManager;
import org.car2x.veins.base.modules.BaseWorldUtility;
import org.car2x.veins.modules.mobility.traci.TraCIScenarioManagerForker;
import org.car2x.veins.modules.obstacle.ObstacleControl;
import org.car2x.veins.modules.world.annotations.AnnotationManager;
import org.car2x.veins.nodes.Car;
import org.car2x.veins.nodes.RSU;


network Manhattan
{
    @display("bgb=845,603");
    submodules:
        annotations: AnnotationManager {
            @display("p=60,37");
        }
        world: BaseWorldUtility {
            @display("p=189,43");
        }
        connectionManager: ConnectionManager {
            @display("p=302,41");
        }
        manager: TraCIScenarioManagerForker {
            @display("p=413,38");
        }
        rsu[2]: RSU {
            
        }
        node[0]: Car {
            @display("p=486,304");
        }
        obstacles: ObstacleControl {
            @display("p=549.94196,41.275997");
        }
    connections allowunconnected:
}
