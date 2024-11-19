from fastapi import FastAPI, Response, status, HTTPException
from fastapi.params import Body
from pydantic import BaseModel
from typing import Optional
from random import randrange
import psycopg2
from psycopg2.extras import RealDictCursor
import time

app = FastAPI()

#creating a class with all the requirements of a post
class post(BaseModel):
    title: str
    content: str
    published: bool = True  #optional field with default


#Establishing database connection
while True:  
    try:
        connection = psycopg2.connect(host = 'localhost', database = 'app', 
                                    user = 'postgres', password = 'a924r1127',
                                    cursor_factory=RealDictCursor)
        cursor = connection.cursor()
        print("Status:  Connection to database was established")
        break
    except Exception as error:
        print("Status:  Connection to database failed")
        print("Error:", error)
        time.sleep(3)


#-------------------------------------------------------------------------
#Default landing page or home page
@app.get("/")
def root():
    return {"message": "Social Media App Api"}

#-------------------------------------------------------------------------

#create a post
@app.post("/posts", status_code= status.HTTP_201_CREATED)
def makePosts(post: post):
    cursor.execute(""" INSERT INTO post (title, content, published) VALUES (%s,%s,%s) RETURNING * """,
                   (post.title, post.content, post.published))
    newPost = cursor.fetchone()
    print(newPost)
    connection.commit()
    return{"data": newPost}

#-------------------------------------------------------------------------
#read or get all the posts you have created
@app.get("/posts")
def getPosts():
    cursor.execute(""" SELECT * FROM post """)
    posts = cursor.fetchall()
    return {"data": posts}

#-------------------------------------------------------------------------
#read specific post by grabbing unique id
@app.get("/posts/{id}")
def getSpecPosts(id: int, response: Response):
    cursor.execute("""SELECT * FROM post WHERE id = %s """, (str(id)),)
    post = cursor.fetchone()
    if not post:
        raise HTTPException(status_code= status.HTTP_404_NOT_FOUND, 
                            detail= f"Post with id: {id} was not found")
    return{"post details": post}

#-------------------------------------------------------------------------
#update whole post or certain aspects of the post
@app.put("/posts/{id}")
def updatePosts(id: int, post: post):
    cursor.execute("""UPDATE post SET title = %s, content = %s, published = %s WHERE id = %s RETURNING *""",
                   (post.title, post.content, post.published, str(id)))
    updatedPost = cursor.fetchone()
    connection.commit()
    if updatedPost == None:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, 
                            detail = f"post with id: {id} was not found")
    return {"data": updatedPost}

#-------------------------------------------------------------------------
#delete post by grabbing id
@app.delete("/posts/{id}", status_code= status.HTTP_204_NO_CONTENT)
def deletePost(id: int):
    cursor.execute("""DELETE FROM post WHERE id = %s returning * """, (str(id)),)
    deletedPost = cursor.fetchone()
    connection.commit()
    if deletedPost == None:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, 
                            detail = f"post with id: {id} was not found")
    return Response(status_code= status.HTTP_204_NO_CONTENT)

#-------------------------------------------------------------------------
