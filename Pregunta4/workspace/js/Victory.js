var TopDownGame = TopDownGame || {};

TopDownGame.Victory = function(){
	this.bg = null;
	this.btnIntentar = null;
	this.btnMenu = null;
};

TopDownGame.Victory.prototype = 
{
	create:function()
	{
		
	
		this.bg = this.add.sprite(0,0,'BG_Win');
		this.bg.width = 800;
		this.bg.height = 600;

		this.fontStyle = {font:'80px Arial',fill:'#FFCC00',stroke: "#333", strokeThickness: 5};
		this.textTiempo = this.add.text(Global.WIDTH/2 - 170,50,'VICTORY!',this.fontStyle);


		this.btnIntentar = this.add.button(0,0,'btn-menu',this.startGame,this,1,0);
		this.btnIntentar.x = Global.WIDTH/2 - this.btnIntentar.width/2;
		this.btnIntentar.y= Global.HEIGHT/2 - this.btnIntentar.height;

		this.fontStyle = {font:'20px Arial',fill:'#FFCC00',stroke: "#333", strokeThickness: 5};
		this.txtInstruccion1 = this.add.text(0,0,'VOLVER A JUGAR',this.fontStyle);
		this.txtInstruccion1.anchor.setTo(0.5,0.5);
		this.txtInstruccion1.x = Global.WIDTH/2;
		this.txtInstruccion1.y = Global.HEIGHT/2 - 10;



	},

	startGame:function()
	{
		this.state.start('Game');
	},


}