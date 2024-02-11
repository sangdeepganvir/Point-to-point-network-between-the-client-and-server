# Point-to-point-network-between-the-client-and-server

# Point-to-Point Network

**Title:**
Design a network scenario between a client and a server using Ns-3, where client communicates
with the server. Establish a Point-to-point network between the client and server. Configure the
network to simulate the following cases and visualize all the provided scenarios with the help
of Network Animation tool (NetAnim) and measure the network throughput for both the cases:

**Two Scenarios**

**--Scenario 1:**

 In every one second of time, make the client send two data packets to the server.
 Set the data link rate of the channel used by the client-server to 10 Mbps.
 Set the data link delay of the channel to 2ms.
 Let the packet sent by the client be of size 1024 bytes.
 Set the simulation time to 20 seconds.

**--Scenario 2:**

 In every one second, make the client send four data packets to the server.
 Set the data link rate of the channel used by the client-server to 20 Mbps.
 Set the data link delay of the channel to 4ms.
 Let the packet sent by the client be of size of 4000 bytes.
 Set the simulation time to 20 seconds.

# Single Server and Multiple Clients

**Title:**
Consider a web hosting scenario where a single server hosts a website and multiple clients (web
browsers) access the server to request and retrieve web pages, such kind of client-server model
frames the backbone of the World Wide Web. Design a basic network scenario including a
server and multiple clients, where clients send their requests to the servers in the form of data
packets.

**Configurations:**
 Configure the network in order to simulate the following described case:

1) Each client should establish a point-to-point link with a server.
2) The number of clients should be settable through the command-line parameter to a maximum of 5.
3) The number of packets sent by each client should also be settable through the commandline parameter to a maximum of 5.
4) Name the command line parameters as “nClients” and “nPackets” for number of clients and number of packets per client respectively.
5) The start times for each clients should be different. All five clients should start randomly within 2 to 7 seconds.
6) Set the stop time for all clients, server and simulation to 20 seconds.
7) Let the data link rate of the channels between the server and each client be 10 Mbps.
8) Let the data link delay for each client-server channel be 5 ms.
9) 
Keeping the above-mentioned parameters constant and vary the packet size sent by the clients
to the server as:
a) 1024 bytes.
b) 4000 bytes.
c) 8000 bytes.
d) 16000 bytes.

Visualize the above mentioned scenario with varying packet sizes graphically using the
NetAnim Animator tool and measure the throughput and delay for all the four cases.

# How to Run Files

**STEPS TO EXECUTE THE CODE USING TERMINAL**

**Step 1**: Save the code in the folder ns3.35/scratch/.

**Step 2**: Open the terminal:

            $ cd home/ns-allinone-3.35/ns3.35/
            
            $ ./ns3 run scratch/filename (No extension of .cc here)

**To run the animation interface:**

            $ cd home/ns-allinone-3.35/netanim-3.108/
            
            $ ./NetAnim
