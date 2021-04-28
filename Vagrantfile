Vagrant.configure("2") do |config|

    # Specify the OS VM Box
    config.vm.box = "ubuntu/bionic64"
    config.vm.box_version = "20190814.0.0"

    # Sync the 'app', 'examples', 'glyphs', and 'src' directories
    config.vm.synced_folder("apps/", "/home/vagrant/apps/",
                            id: "appsdir",
                            :create => true,
                            type: "virtualbox")
    config.vm.synced_folder("examples/", "/home/vagrant/apps/ledger-app-bind/examples/",
                            id: "examplesdir",
                            :create => true,
                            type: "virtualbox")
    config.vm.synced_folder("glyphs/", "/home/vagrant/apps/ledger-app-bind/glyphs/",
                            id: "glyphsdir",
                            :create => true,
                            type: "virtualbox")
    config.vm.synced_folder("src/", "/home/vagrant/apps/ledger-app-bind/src/",
                            id: "srcdir",
                            :create => true,
                            type: "virtualbox")

    # Copy scripts and the Makefile to the VM
    config.vm.provision("file",
                        source: "./scripts/rebuild.sh",
                        destination: "/home/vagrant/apps/ledger-app-bind/scripts/")
    config.vm.provision("file",
                        source: "./scripts/rebuild_nanos.sh",
                        destination: "/home/vagrant/apps/ledger-app-bind/scripts/")
    config.vm.provision("file",
                        source: "./scripts/rebuild_nanox.sh",
                        destination: "/home/vagrant/apps/ledger-app-bind/scripts/")
    config.vm.provision("file",
                        source: "./scripts/udev.sh",
                        destination: "/home/vagrant/apps/ledger-app-bind/scripts/")
    config.vm.provision("file",
                        source: "./Makefile",
                        destination: "/home/vagrant/apps/ledger-app-bind/")

    # Copy Icons
    config.vm.provision("file",
                        source: "./icons/nanos_app_bind.gif",
                        destination: "/home/vagrant/apps/ledger-app-bind/icons/")
    config.vm.provision("file",
                        source: "./icons/nanox_app_bind.gif",
                        destination: "/home/vagrant/apps/ledger-app-bind/icons/")
                        config.vm.provision("file",
                        source: "./icons/icon.gif",
                        destination: "/home/vagrant/apps/ledger-app-bind/icons/")

    # VM configuration
    config.vm.provider "virtualbox" do |v|
        v.name = "Compendia Ledger App Development Box"
        v.customize ["modifyvm", :id, "--memory", "1024"]

        # Configure the Ledger Nano S/X USB connection
        v.customize ["modifyvm", :id, "--usb", "on"]
        v.customize ["modifyvm", :id, "--usbehci", "on"]
        v.customize ["usbfilter", "add", "0",
                     "--target", :id,
                     "--name", "Ledger Nano S/X",
                     "--manufacturer", "Ledger",
                     "--product", "Nano S/X"]
    end

    # Run the Provisioning script
    config.vm.provision "shell" do |s|
        s.path = "scripts/provision.sh"
    end
end
