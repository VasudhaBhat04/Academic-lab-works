#To create scenario & study the performance of token bus protocol through simulator 
(Bus topology)

set ns [new Simulator]
set tr [open lab6.tr w]
$ns trace-all $tr
set nam [open lab6.nam w]
$ns namtrace-all $nam

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

$ns make-lan "$n0 $n1 $n2 $n3 $n4 $n5" 5Mb 10ms LL Queue/DropTail Mac/802_3
set tcp [new Agent/TCP]
set sink [new Agent/TCPSink]

$ns attach-agent $n1 $tcp
$ns attach-agent $n5 $sink
$ns connect $tcp $sink

set cbr [new Application/Traffic/CBR]
$cbr attach-agent $tcp
$tcp set fid_ 1
$tcp set fid_ 2

proc finish {} {
global ns tr nam
$ns flush-trace
close $tr
close $nam
exec nam lab6.nam &
exit 0
}

$ns at 0.0 "$cbr start"
$ns at 10.0 "finish"
$ns run