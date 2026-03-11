for N = 2, 32 do
  local A = {}
  for Y = 0, 10000 do
    local c = (Y // 2) % N
    local r0 = (Y + (Y & (N * (N - 1)))) % N
    A[c * N + r0] = true
  end
  io.write(string.format('N = %d\n', N))
  for c = 0, N - 1 do
    for r0 = 0, N - 1 do
      io.write(A[c * N + r0] and '* ' or '  ')
    end
    io.write('\n')
  end
  io.write('\n')
end
