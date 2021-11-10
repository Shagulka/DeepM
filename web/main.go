package main

import (
	"bytes"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"os"
)

type trans struct {
	Text        string `json:"text"`
	Translation string `json:"translation"`
}

type Quote struct {
	Quotes []trans
}

func addQuote(quote string) {
	client := &http.Client{}
	values := map[string]string{"rowid": "0", "text": quote}
	data, err := json.Marshal(values)
	req, err := http.NewRequest("POST", "https://g648e561ebb875c-db202111100919.adb.eu-amsterdam-1.oraclecloudapps.com/ords/admin/deepmtable/", bytes.NewBuffer(data))
	if err != nil {
		log.Fatal(err)
	}
	req.Header.Set("Content-Type", "application/json")
	resp, err := client.Do(req)
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close()
	bodyText, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("%s\n", bodyText)
}

func handler(w http.ResponseWriter, r *http.Request) {
	if r.URL.Path[1:] != "favicon.ico" && r.URL.Path[1:] != "json" {
		_, _ = fmt.Fprintf(w, "Цитата : %s", r.URL.Path[1:])
		addQuote(r.URL.Path[1:])
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
	log.Fatal(http.ListenAndServe(":"+port, nil))
}
