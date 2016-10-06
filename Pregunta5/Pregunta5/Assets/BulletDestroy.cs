using UnityEngine;
using System.Collections;

public class BulletDestroy : MonoBehaviour {

    float lifetime = 1.0f;
    void Awake()
    {
        Destroy(gameObject, lifetime);
    }

}
