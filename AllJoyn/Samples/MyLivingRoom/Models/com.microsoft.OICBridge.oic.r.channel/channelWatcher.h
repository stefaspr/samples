//-----------------------------------------------------------------------------
// <auto-generated> 
//   This code was generated by a tool. 
// 
//   Changes to this file may cause incorrect behavior and will be lost if  
//   the code is regenerated.
//
//   Tool: AllJoynCodeGenerator.exe
//
//   This tool is located in the Windows 10 SDK and the Windows 10 AllJoyn 
//   Visual Studio Extension in the Visual Studio Gallery.  
//
//   The generated code should be packaged in a Windows 10 C++/CX Runtime  
//   Component which can be consumed in any UWP-supported language using 
//   APIs that are available in Windows.Devices.AllJoyn.
//
//   Using AllJoynCodeGenerator - Invoke the following command with a valid 
//   Introspection XML file and a writable output directory:
//     AllJoynCodeGenerator -i <INPUT XML FILE> -o <OUTPUT DIRECTORY>
// </auto-generated>
//-----------------------------------------------------------------------------
#pragma once

namespace com { namespace microsoft { namespace OICBridge { namespace oic { namespace r { namespace channel {

ref class channelWatcher;

public interface class IchannelWatcher
{
    event Windows::Foundation::TypedEventHandler<channelWatcher^, Windows::Devices::AllJoyn::AllJoynServiceInfo^>^ Added;
    event Windows::Foundation::TypedEventHandler<channelWatcher^, Windows::Devices::AllJoyn::AllJoynProducerStoppedEventArgs^>^ Stopped;
};

public ref class channelWatcher sealed : [Windows::Foundation::Metadata::Default] IchannelWatcher
{
public:
    channelWatcher(Windows::Devices::AllJoyn::AllJoynBusAttachment^ busAttachment);
    virtual ~channelWatcher();

    // This event will fire whenever a producer for this service is found.
    virtual event Windows::Foundation::TypedEventHandler<channelWatcher^, Windows::Devices::AllJoyn::AllJoynServiceInfo^>^ Added;

    // This event will fire whenever the watcher is stopped.
    virtual event Windows::Foundation::TypedEventHandler<channelWatcher^, Windows::Devices::AllJoyn::AllJoynProducerStoppedEventArgs^>^ Stopped;

    // Start watching for producers advertising this service.
    void Start();

    // Stop watching for producers for this service.
    void Stop();

internal:
    void OnAnnounce(
        _In_ PCSTR name,
        _In_ uint16_t version,
        _In_ alljoyn_sessionport port,
        _In_ alljoyn_msgarg objectDescriptionArg,
        _In_ const alljoyn_msgarg aboutDataArg);

    void OnPropertyChanged(_In_ PCSTR prop_name, _In_ alljoyn_msgarg prop_value)
    {
        UNREFERENCED_PARAMETER(prop_name); UNREFERENCED_PARAMETER(prop_value);
    }

    property Windows::Devices::AllJoyn::AllJoynBusAttachment^ BusAttachment
    {
        Windows::Devices::AllJoyn::AllJoynBusAttachment^ get() { return m_busAttachment; }
    }
    
    property std::string BusObjectInterfaceName
    {
        std::string get() { return m_objectInterfaceName; }
    }

    // Stop watching for producers advertising this service and pass status to anyone listening for the Stopped event.
    void StopInternal(int32 status);

    void BusAttachmentStateChanged(_In_ Windows::Devices::AllJoyn::AllJoynBusAttachment^ sender, _In_ Windows::Devices::AllJoyn::AllJoynBusAttachmentStateChangedEventArgs^ args);

private:
    void UnregisterFromBus();

    Windows::Devices::AllJoyn::AllJoynBusAttachment^ m_busAttachment;
    Windows::Foundation::EventRegistrationToken m_busAttachmentStateChangedToken;

    alljoyn_aboutlistener m_aboutListener;
    
    // Used to pass a pointer to this class to callbacks.
    Platform::WeakReference* m_weak;

    std::string m_objectInterfaceName;
};

} } } } } } 