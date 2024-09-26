require 'algorithms'

graph = {
  0 => [1, 4, 5],
  1 => [0, 4, 2, 3],
  3 => [1, 2, 6],
  6 => [3],
  2 => [1, 3],
  4 => [0, 1],
  5 => [0]
}

def dfs(graph, curr_node, is_visited)
  # Processing
  print(curr_node.to_s + ", ")

  is_visited[curr_node] = true

  graph[curr_node].each do |neighbor|
    unless is_visited[neighbor]
      dfs(graph, neighbor, is_visited)
    end
  end
end

def bfs(graph, start)
  pending = Containers::Queue.new
  is_visited = {}

  is_visited[start] = true
  pending.push(start)

  while !pending.empty?()
    elements_right_now = pending.size()

    elements_right_now.times do
      curr_ele = pending.next()

      # Processing
      print(curr_ele.to_s + ", ")

      pending.pop()

      graph[curr_ele].each do |neighbor|
        unless is_visited[neighbor]
          is_visited[neighbor] = true
          pending.push(neighbor)
        end
      end
    end
  end
end

# dfs(graph, 1, {})
# puts ""
# 1, 0, 4, 5, 2, 3, 6

bfs(graph, 1)
puts ""
# 1, 0, 4, 2, 3, 5, 6

# Cycle in Directed graph
# Cycle in Undirected Graph
# Topological Sort
