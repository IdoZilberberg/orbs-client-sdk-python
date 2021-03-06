#include <boost/python.hpp>

#include "../native/headers/ed25519key.h"
#include "../native/headers/utils.h"

using namespace std;
using namespace boost::python;
using namespace Orbs;

void ExportED25519() {
    class_<ED25519Key, boost::noncopyable>("ED25519Key", init<>())
        .def(init<string>())
        .def(init<string, string>())
        .add_property("public_key", +[](const ED25519Key &k) {
            return Utils::Vec2Hex(k.GetPublicKey());
        })
        .add_property("unsafe_private_key", +[](const ED25519Key &k) {
            return Utils::Vec2Hex(k.GetPrivateKeyUnsafe());
        })
        .add_property("has_private_key", &ED25519Key::HasPrivateKey)
        .def("sign", +[](const ED25519Key &k, const string &message) {
            const vector<uint8_t> rawMessage(message.cbegin(), message.cend());

            return Utils::Vec2Hex(k.Sign(rawMessage));
        })
        .def("verify", +[](const ED25519Key &k, const string &message, const string &signature) {
            const vector<uint8_t> rawMessage(message.cbegin(), message.cend());
            const vector<uint8_t> rawSignature(Orbs::Utils::Hex2Vec(signature));

            return k.Verify(rawMessage, rawSignature);
        })
    ;
}
