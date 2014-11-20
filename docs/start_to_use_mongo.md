# MongoDB User Handbook

## Installation on Debain
```
sudo apt-key adv --keyserver keyserver.ubuntu.com --recv 7F0CEB10
echo 'deb http://downloads-distro.mongodb.org/repo/debian-sysvinit dist 10gen' | sudo tee /etc/apt/sources.list.d/mongodb.list
sudo apt-get update
sudo apt-get install -y mongodb-org
```

If db cant start currectly, and log says
`Please make at least 3379MB available in /var/lib/mongodb/journal or use --smallfiles`
set `smallfiles=true` in conf file

## Base Info
* config file path: /etc/mongod.conf
* dbpath=/var/lib/mongodb
* use `sudo service mongod {start|stop|force-stop|restart|force-reload|status}` to manage mongos daemon

## Usage
#### manage cmd
* show dbs
    admin  (empty)
    local  0.031GB
    sales  0.031GB
    test   0.031GB

* db
    sales

* show collections
    system.indexes
    testData
    users

### [curd](http://docs.mongodb.org/manual/core/crud-introduction/)

- select
  * db.users.find()
    { "_id" : ObjectId("546c2bf4d9a4d37973ac3c38"), "name" : "wyx", "age" : 22 }
    { "_id" : ObjectId("546ca3b669ce8b0d372ff910"), "email" : "ttt", "password" : "9990775155c3518a0d7917f7780b24aa" }
    { "_id" : ObjectId("546ca40875417d1a374bb98b"), "email" : "sss", "password" : "9f6e6800cfae7749eb6c486619254b9c" }

  * db.users.find().limit(1)
    { "_id" : ObjectId("546c2bf4d9a4d37973ac3c38"), "name" : "wyx", "age" : 22 }

  * db.testData.find( { email : 'sss' } )
    { "_id" : ObjectId("546ca40875417d1a374bb98b"), "email" : "sss", "password" : "9f6e6800cfae7749eb6c486619254b9c" }

  * db.users.find({name: 'wyx'}, {_id: 0})
    { "name" : "wyx", "age" : 22 }

- insert
  * db.users.insert({name: 'test', age: 18})

- [update](http://docs.mongodb.org/manual/tutorial/modify-documents/)

- delete
  * db.users.remove({}) // remove all documents from a collection
  * db.users.drop() // drop all collection

  * db.users.remove( { name : "wyx" } ) // remove document where the name field equals wyx
  * db.users.remove( { name : "wyx" }, 1 ) // remove a single document


## TODO:

Reading:
    http://docs.mongodb.org/manual/core/crud/
    http://docs.mongodb.org/manual/reference/crud/
    http://docs.mongodb.org/manual/core/write-concern/#write-concern
