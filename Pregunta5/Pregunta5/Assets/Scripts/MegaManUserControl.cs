using UnityEngine;
using System.Collections;
[RequireComponent(typeof(MegaMan))]
public class MegaManUserControl : MonoBehaviour {
        private MegaMan m_Character;
        private bool m_Jump;

        private void Awake()
        {
            m_Character = GetComponent<MegaMan>();
        }


        private void Update()
        {
            if (!m_Jump)
            {
                m_Jump = Input.GetKeyDown(KeyCode.Space);
            }
        }


        private void FixedUpdate()
        {
        bool Run = Input.GetKey(KeyCode.LeftShift);
        bool Shoot = Input.GetKeyDown(KeyCode.Z);

        float h = Input.GetAxis("Horizontal");
            // pasamos los parámetro al caracter controller.
            m_Character.Move(h, Run, m_Jump,Shoot);
            m_Jump = false;
        }
}
