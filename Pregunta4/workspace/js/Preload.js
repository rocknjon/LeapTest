var TopDownGame = TopDownGame || {};

TopDownGame.Preload = function(){};

TopDownGame.Preload.prototype = {
  preload: function() {
    this.preloadBar = this.add.sprite(this.game.world.centerX, this.game.world.centerY, 'preloadbar');
    this.preloadBar.anchor.setTo(0.5);

    this.load.setPreloadSprite(this.preloadBar);

    this.load.tilemap('level1', 'assets/tilemaps/level1.json', null, Phaser.Tilemap.TILED_JSON);
    this.load.image('gameTiles', 'assets/images/tiles.png');
    this.load.image('puas', 'assets/images/puas.png');
    this.load.image('bluecup', 'assets/images/bluecup.png');
    this.load.image('player', 'assets/images/player.png');
    this.load.image('browndoor', 'assets/images/browndoor.png');
    this.load.image('BG_Win','assets/images/BG_Win.png')
    
  },
  create: function() {
    this.state.start('Game');
  }
};