package main

import (
    "net/http"

    "github.com/gin-gonic/gin"
)

type album struct {
    ID     string  `json:"id"`
    Title  string  `json:"title"`
    Artist string  `json:"artist"`
}

var albums = []album{
    {ID: "1", Title: "asdasd", Artist: "asdasdasdas"},
    {ID: "2", Title: "asdasd", Artist: "asdasdasdas",},
    {ID: "3", Title: "asdasd", Artist: "asdasdasdaa",},
}

func main() {
    router := gin.Default()
    router.GET("/test", getAlbums)
    router.GET("/test/:id", getAlbumByID)
    router.POST("/post_test", postAlbums)

    router.Run("0.0.0.0:666")
}

func getAlbums(c *gin.Context) {
    c.IndentedJSON(http.StatusOK, albums)
}

func postAlbums(c *gin.Context) {
    var newAlbum album

    if err := c.BindJSON(&newAlbum); err != nil {
        return
    }

    albums = append(albums, newAlbum)
    c.IndentedJSON(http.StatusCreated, newAlbum)
}

func getAlbumByID(c *gin.Context) {
    id := c.Param("id")

    for _, a := range albums {
        if a.ID == id {
            c.IndentedJSON(http.StatusOK, a)
            return
        }
    }
    c.IndentedJSON(http.StatusNotFound, gin.H{"message": "album not found"})
}
