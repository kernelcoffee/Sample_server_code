#!/bin/env ruby
require 'socket'

server = TCPServer.new 4500
loop do
  puts "Listeging on port 4500"
  Thread.start(server.accept) do |client|
    puts "new client"
    while received = client.gets
      puts received
    end
#    client.puts "Hello !"
#    client.close
  end
end
