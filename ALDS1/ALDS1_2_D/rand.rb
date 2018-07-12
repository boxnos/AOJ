rand = Random.new
n = 1000000

puts n
n.times do
  puts rand.rand(1..10**9)
end
