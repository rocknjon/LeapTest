using UnityEngine;
using System.Collections;

public class MegaMan : MonoBehaviour {
    [SerializeField]
    private float m_MaxSpeed = 10f;                    
    [SerializeField]
    private float m_JumpForce = 400f;                
    [SerializeField]
    private bool m_AirControl = false; //permite moverte hacia los lados en el aire             
    [SerializeField]
    private LayerMask WhatIsGround;
    public GameObject bulletPrefab;
    private GameObject ShootPoint;
    private GameObject bullet;
    private Transform Grounded;    

    const float k_GroundedRadius = .1f; // Radio del circulo que indica si esta en tierra
    private bool m_Grounded;            // Bool que indica si esta grounded
    private Animator Anim;            // Reference to the player's animator component.
    private Rigidbody2D Rigidbody2D;
    private bool FacingRight = true;  // Variable que nos dice si el player esta mirando hacia la derecha


    private void Awake()
    {
        // Setting up references.
        ShootPoint = GameObject.Find("ShootPoint");
        Grounded = transform.Find("Grounded");
        Anim = GetComponent<Animator>();
        Rigidbody2D = GetComponent<Rigidbody2D>();
    }


    private void FixedUpdate()
    {
        m_Grounded = false;
  
        Collider2D[] colliders = Physics2D.OverlapCircleAll(Grounded.position, k_GroundedRadius, WhatIsGround); //revisamos las colisiones 
        for (int i = 0; i < colliders.Length; i++)
        {
            if (colliders[i].gameObject != gameObject)
                m_Grounded = true;
        }
        Anim.SetBool("Grounded", m_Grounded);
        Anim.SetFloat("vSpeed", Rigidbody2D.velocity.y);
    }


    public void Move(float move, bool Run, bool jump, bool shoot)
    {
          
        //Si esta corriendo el player
        Anim.SetBool("Run", Run);


        //Solo mover si esta Grounded y aircontrol esta prendido
        if (m_Grounded || m_AirControl)
        {
            // Le dices al animator que estas moviento tu personaje
            Anim.SetFloat("Speed", Mathf.Abs(move));

            // Mueve el personaje a diferentes velocidades, si esta corrie
            if (Run)
                Rigidbody2D.velocity = new Vector2(move * 2f * m_MaxSpeed, Rigidbody2D.velocity.y);
            else
            {
                Rigidbody2D.velocity = new Vector2(move * m_MaxSpeed, Rigidbody2D.velocity.y);
            }

            // Si estas moviendote hacia la derecha y el jugador esta mirando a la izquierda
            if (move > 0 && !FacingRight)
            {
                Flip();
            }
            else if (move < 0 && FacingRight)
            {
                Flip();
            }
        }
        // revisar si el jugador puede saltar.
        if (m_Grounded && jump && Anim.GetBool("Grounded"))
        {
            // Add a vertical force to the player.
            m_Grounded = false;
            Anim.SetBool("Grounded", false);
            Rigidbody2D.AddForce(new Vector2(0f, m_JumpForce));
        }
        //Si ha presionado el boton de disparar
        if (m_Grounded && shoot)
        {
            Anim.SetBool("Shoot", true);
            Shoot();
        }
        

    }
    private void Shoot()
    {
        bullet = Instantiate(bulletPrefab, ShootPoint.transform.position, Quaternion.identity) as GameObject;
        if (FacingRight)
            bullet.GetComponent<Rigidbody2D>().velocity = new Vector2(10, 0);
        else
        {
            bullet.GetComponent<Rigidbody2D>().velocity = new Vector2(-10, 0);
        }
    }


    private void Flip()
    {
        FacingRight = !FacingRight;
        Vector3 theScale = transform.localScale;
        theScale.x *= -1;
        transform.localScale = theScale;
    }
}
