using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class server : MonoBehaviour {

    public bool Connected;
    private NetMqPublisher _netMqPublisher;
    private string _response;

    private void Start()
    {
        _netMqPublisher = new NetMqPublisher(HandleMessage);
        _netMqPublisher.Start();
    }

    private void Update()
    {
        var position = transform.position;
        _response = "position:" + position.x + "," + position.y + "," + position.z +"\n";//$"{position.x} {position.y} {position.z}";
        Connected = _netMqPublisher.Connected;
    }

    private string HandleMessage(string message)
    {
        // Not on main thread
        return _response;
    }

    private void OnDestroy()
    {
        _netMqPublisher.Stop();
    }
}
