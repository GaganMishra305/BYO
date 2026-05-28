N=${1:-5}
# run up N servers on port 10000-1000(N-1)
echo "Starting $N servers on ports 10000-1000$((N-1))"
cd backend
for i in $(seq 0 $((N-1))); do
    port=$((10000 + i))
    go run main.go $port &
done

# run up the load balancer on port 5000
echo "Starting load balancer on port 5000"
cd ..
go run main.go
