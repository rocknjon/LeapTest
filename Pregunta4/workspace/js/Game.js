var TopDownGame = TopDownGame || {};

//title screen
TopDownGame.Game = function(){};

TopDownGame.Game.prototype = {
  create: function() {
    this.map = this.game.add.tilemap('level1');

    this.map.addTilesetImage('tiles', 'gameTiles');

    this.backgroundlayer = this.map.createLayer('backgroundLayer');
    this.blockedLayer = this.map.createLayer('blockedLayer');
    this.map.setCollisionBetween(1, 2000, true, 'blockedLayer');
    this.backgroundlayer.resizeWorld();
    this.createItems();
    this.createDoors();    
    var result = this.findObjectsByType('playerStart', this.map, 'objectsLayer')
    this.player = this.game.add.sprite(result[0].x, result[0].y, 'player');
    this.player.scale.setTo(0.2,0.2);
    this.player.anchor.setTo(0.5,0.5);
    this.game.physics.arcade.enable(this.player);

    this.game.camera.follow(this.player);
    this.cursors = this.game.input.keyboard.createCursorKeys();

  },
  createItems: function() {
    this.items = this.game.add.group();
    this.items.enableBody = true;
    var item;    
    result = this.findObjectsByType('item', this.map, 'objectsLayer');
    result.forEach(function(element){
      this.createFromTiledObject(element, this.items);
    }, this);
  },
  createDoors: function() {
    this.doors = this.game.add.group();
    this.doors.enableBody = true;
    result = this.findObjectsByType('door', this.map, 'objectsLayer');

    result.forEach(function(element){
      this.createFromTiledObject(element, this.doors);
    }, this);
  },
  findObjectsByType: function(type, map, layer) {
    var result = new Array();
    map.objects[layer].forEach(function(element){
      if(element.properties.type === type) {
        element.y -= map.tileHeight;
        result.push(element);
      }      
    });
    return result;
  },
  createFromTiledObject: function(element, group) {
    var sprite = group.create(element.x, element.y, element.properties.sprite);

      Object.keys(element.properties).forEach(function(key){
        sprite[key] = element.properties[key];
      });
  },
  update: function() {
    this.game.physics.arcade.collide(this.player, this.blockedLayer);
    this.game.physics.arcade.overlap(this.player, this.items, this.die, null, this);
    this.game.physics.arcade.overlap(this.player, this.doors, this.enterDoor, null, this);

    this.player.body.velocity.x = 0;

    if(this.cursors.up.isDown) {
      if(this.player.body.velocity.y == 0)
      this.player.body.velocity.y -= 50;
      if(this.player.angle != -90)
        this.player.angle = -90;
    }
    else if(this.cursors.down.isDown) {
      if(this.player.body.velocity.y == 0)
      this.player.body.velocity.y += 50;
       if(this.player.angle != 90)
        this.player.angle = 90;
    }
    else {
      this.player.body.velocity.y = 0;
    }
    if(this.cursors.left.isDown) {
      this.player.body.velocity.x -= 50;
       if(this.player.angle != 180)
        this.player.angle = 180;
    }
    else if(this.cursors.right.isDown) {
      this.player.body.velocity.x += 50;
       if(this.player.angle != 0)
        this.player.angle = 0;
    }
  },
  die: function(player, collectable) {
    console.log('yummy!');

    this.game.state.start("Game");
  },
  enterDoor: function(player, door) {
    //this.game.state.start("Victory");
  },
};