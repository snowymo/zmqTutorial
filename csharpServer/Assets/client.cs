using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class client : MonoBehaviour {

    public string msg;
    public float[] fm;

    private NetMqListener _netMqListener;

    public string topic;

    private void HandleMessage(string message)
    {
        //         var splittedStrings = message.Split(' ');
        //         if (splittedStrings.Length != 3) return;
        //         var x = float.Parse(splittedStrings[0]);
        //         var y = float.Parse(splittedStrings[1]);
        //         var z = float.Parse(splittedStrings[2]);
        //         transform.position = new Vector3(x, y, z);
        msg = message;
    }

    private void HandleFMessage(byte[] b)
    {
        //         var splittedStrings = message.Split(' ');
        //         if (splittedStrings.Length != 3) return;
        //         var x = float.Parse(splittedStrings[0]);
        //         var y = float.Parse(splittedStrings[1]);
        //         var z = float.Parse(splittedStrings[2]);
        //         transform.position = new Vector3(x, y, z);
        Buffer.BlockCopy(b, 0, fm, 0, 4);
        //fm = f;
    }

    private void Start()
    {
        _netMqListener = new NetMqListener(HandleMessage, HandleFMessage, topic);
        _netMqListener.Start();

        fm = new float[1];
    }

    private void Update()
    {
        _netMqListener.Update();
    }

    private void OnDestroy()
    {
        _netMqListener.Stop();
    }
}
