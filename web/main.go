package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
)

type trans struct {
	Text        string `json:"text"`
	Translation string `json:"translation"`
}

type Quote struct {
	Quotes []trans
}

var a Quote

func handler(w http.ResponseWriter, r *http.Request) {
	if r.URL.Path[1:] != "favicon.ico" && r.URL.Path[1:] != "json" {
		_, err := fmt.Fprintf(w, "Цитата : %s", r.URL.Path[1:])
		if err != nil {
			return
		}
		a.Quotes = append(a.Quotes, trans{r.URL.Path[1:], r.URL.Path[1:]})
		updater(a)
	} else if r.URL.Path[1:] == "json" {
		file, _ := json.MarshalIndent(a, "", " ")
		_, err := fmt.Fprintf(w, "%s", file)
		if err != nil {
			return
		}
	}

}

func updater(a Quote) {
	file, _ := json.MarshalIndent(a, "", " ")
	_ = ioutil.WriteFile("test.json", file, 0644)
}

func main() {
	port := os.Getenv("PORT")
        if port == "" {
                port = "8080"
                log.Printf("defaulting to port %s", port)
        }
	http.HandleFunc("/", handler)
	log.Fatal(http.ListenAndServe(":" + port, nil))
}
