using UnityEngine;
using System.Collections;

public class FollowPlayer : MonoBehaviour {
    public GameObject Player;
	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void FixedUpdate () {
        transform.position = Player.transform.position;
	}
}
