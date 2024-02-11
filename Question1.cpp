#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/netanim-module.h"
#include "ns3/internet-stack-helper.h"
#include "ns3/ipv4-address-helper.h"
#include "ns3/ipv4-interface-container.h"

using namespace ns3;

int main (int argc, char *argv[]) {
  // Set the simulation time
  uint32_t simulationTime = 20; // seconds

  // Create nodes
  NodeContainer nodes;
  nodes.Create (2);

  // Set up point-to-point link
  PointToPointHelper pointToPoint;
  pointToPoint.SetDeviceAttribute ("DataRate", DataRateValue (DataRate ("10Mbps")));
  pointToPoint.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (2)));

  NetDeviceContainer devices;
  devices = pointToPoint.Install (nodes);

  // Install internet stack on nodes
  InternetStackHelper stack;
  stack.Install (nodes);

  // Assign IP addresses
  Ipv4AddressHelper address;
  address.SetBase ("10.1.1.0", "255.255.255.0");
  Ipv4InterfaceContainer interfaces = address.Assign (devices);

  // Install applications
  uint32_t packetSizeScenario1 = 1024;
  uint32_t packetSizeScenario2 = 4000;

  // Scenario 1
  uint32_t packetsPerSecondScenario1 = 2;
  OnOffHelper onOffHelper1 ("ns3::TcpSocketFactory", Address (InetSocketAddress (interfaces.GetAddress (1), 9)));
  onOffHelper1.SetAttribute ("PacketSize", UintegerValue (packetSizeScenario1));
  onOffHelper1.SetAttribute ("OnTime", StringValue ("ns3::ConstantRandomVariable[Constant=1]"));
  onOffHelper1.SetAttribute ("OffTime", StringValue ("ns3::ConstantRandomVariable[Constant=0]"));
  onOffHelper1.SetAttribute ("DataRate", DataRateValue (DataRate ("10Mbps")));
  ApplicationContainer appsScenario1 = onOffHelper1.Install (nodes.Get (0));
  appsScenario1.Start (Seconds (1));
  appsScenario1.Stop (Seconds (simulationTime));

  // Scenario 2
  uint32_t packetsPerSecondScenario2 = 4;
  OnOffHelper onOffHelper2 ("ns3::TcpSocketFactory", Address (InetSocketAddress (interfaces.GetAddress (1), 9)));
  onOffHelper2.SetAttribute ("PacketSize", UintegerValue (packetSizeScenario2));
  onOffHelper2.SetAttribute ("OnTime", StringValue ("ns3::ConstantRandomVariable[Constant=1]"));
  onOffHelper2.SetAttribute ("OffTime", StringValue ("ns3::ConstantRandomVariable[Constant=0]"));
  onOffHelper2.SetAttribute ("DataRate", DataRateValue (DataRate ("20Mbps")));
  ApplicationContainer appsScenario2 = onOffHelper2.Install (nodes.Get (0));
  appsScenario2.Start (Seconds (1));
  appsScenario2.Stop (Seconds (simulationTime));

  // Enable NetAnim
  AnimationInterface anim("animation.xml");

  // Run simulation
  Simulator::Stop (Seconds (simulationTime));
  Simulator::Run ();
  Simulator::Destroy ();

  return 0;
}
