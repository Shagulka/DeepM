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
		fmt.Fprintf(w, "Цитата матвея: %s!", r.URL.Path[1:])
		a.Quotes = append(a.Quotes, trans{r.URL.Path[1:], r.URL.Path[1:]})
		updater(a)
	} else if r.URL.Path[1:] == "json"{
		file, _ := json.MarshalIndent(a, "", " ")
		fmt.Fprintf(w, "%s", file)
	}

}

func updater(a Quote) {
	file, _ := json.MarshalIndent(a, "", " ")
	_ = ioutil.WriteFile("test.json", file, 0644)
}

func main() {
	http.HandleFunc("/", handler)
	log.Fatal(http.ListenAndServe(":8080", nil))
}
