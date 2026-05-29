trap 'kill $(jobs -p)' EXIT

N=${1:-5}
# run up N servers on port 10000-1000(N-1)
echo "Starting $N servers on ports 10000-1000$((N-1))"
cd backend
SN=0
for i in $(seq 0 $((N-1))); do
    port=$((10000 + i))
    go run main.go $port &
    if [ $? -eq 0 ]; then
        SN=$((SN+1))
    fi
done

# run up the load balancer on port 5000
cd ..
go run main.go $SN
