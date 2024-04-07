def length_of_longest_substring(s)
  return 0 if s.empty?

  l = 0
  h = {}
  i = 0
  j = 0
  s.each_char do |c|
      if !h[c].nil? && (new_i = h[c] + 1) > i
          i = new_i
      end
      h[c] = j
      if (curr_len = (j - i + 1)) > l
          l = curr_len
      end
      j += 1
  end
  l
end
