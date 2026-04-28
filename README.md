# AS-7: AegisSwarm-7
*Autonomous Drone Swarm Defense System*

---
# AegisSwarm-7 (AS-7)

AegisSwarm-7 (AS-7) is a C++ simulation designed to revolutionize air defense through decentralized, autonomous drone swarms. Shifting away from traditional, stationary, and "single-brain" radar systems, AS-7 implements a distributed intelligence model to act as a resilient Digital Shield against modern aerial threats.

The system is specifically engineered to address the "cost-asymmetry" of modern warfare—using low-cost, smart interceptors to neutralize expensive ballistic threats and loitering munitions while safeguarding critical civilian infrastructure.

### 🛡️ Key Features

**Decentralized Swarm Logic:** Eliminates single points of failure by allowing drones to communicate coordinates and status, ensuring the perimeter remains secure even if units are lost.

**Location Shield (No-Fire Zones):** Intelligent coordinate checking that prevents interceptions over sensitive areas such as hospitals, schools, and power plants.

**Target Prioritization:** A risk-assessment engine that ranks incoming threats (1-10) and optimizes resource allocation to prevent "overkill" on decoys.

**Automatic Handover Logic:** Real-time power management that coordinates seamless replacements for drones with low battery levels, ensuring 24/7 operational readiness.

**Multi-Threat Trajectory Physics:** Custom physics engines for simulating Ballistic Missile arcs, Loitering Munition zig-zag paths, and Electronic Decoys.

### 💻 Technical Architecture

The project leverages advanced Object-Oriented Programming (OOP) principles to simulate a complex battlefield grid:

* **Inheritance & Polymorphism:** Abstract base classes for Interceptor and Threat units.
* **Composition & Aggregation:** Drones are composed of SensorArray and Battery components, while the CommandCenter aggregates Infrastructure for the Location Shield.
* **Operator Overloading:** Custom logic for Coordinate math and TargetProfile ranking.

### 🛠️ Built With

* **Language:** C++
* **Environment:** VS Code / Dev C++
* **Version Control:** Git & GitHub
