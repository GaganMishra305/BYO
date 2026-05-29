package main

import (
	"fmt"
	"log"
	"net/http"
	"net/http/httputil"
	"net/url"
	"os"
	"strconv"
)

func main() {
	// time.Sleep(1 * time.Second) // wait for 2 seconds for all the servers to startup
	num := os.Args[1]
	tot, _ := strconv.Atoi(num)
	fmt.Printf("Numbers of servers successfully started = " + num + "\n")
	fmt.Printf("Started load balancer on 8080\n")

	var backends []*url.URL
	for i := 0; i < tot; i++ {
		port := 10000 + i
		backendURL, err := url.Parse("http://localhost:" + strconv.Itoa(port))
		if err != nil {
			log.Fatalf("Failed to parse backend URL: %v", err)
		}
		backends = append(backends, backendURL)
	}

	cur := -1
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		cur = (cur + 1) % tot
		backendURL := backends[cur]
		proxy := httputil.NewSingleHostReverseProxy(backendURL)

		// Log the incoming request
		requestDump, err := httputil.DumpRequest(r, true)
		if err != nil {
			fmt.Println(err)
		}
		fmt.Println("Received request from", r.RemoteAddr)
		fmt.Println("Forwarding to", backendURL)
		fmt.Println(string(requestDump))
		proxy.ServeHTTP(w, r)
	})

	log.Fatal(http.ListenAndServe(":8080", nil))
}
