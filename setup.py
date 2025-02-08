import os
import json
import platform
from pathlib import Path

def generate_vscode_configs():
    # Read templates
    with open('.vscode/launch.json.template', 'r') as f:
        launch_config = json.load(f)
    
    with open('.vscode/tasks.json.template', 'r') as f:
        tasks_config = json.load(f)
    
    # Detect system-specific paths
    if platform.system() == 'Windows':
        openocd_path = os.getenv('OPENOCD_PATH', 'C:/Program Files/OpenOCD/share/openocd/scripts')
    else:
        openocd_path = os.getenv('OPENOCD_PATH', '/usr/local/share/openocd/scripts')
    
    # Update paths in launch configuration
    launch_config['configurations'][0]['configFiles'] = [
        path.replace('${env:OPENOCD_PATH}', openocd_path)
        for path in launch_config['configurations'][0]['configFiles']
    ]
    
    # Create .vscode directory if it doesn't exist
    os.makedirs('.vscode', exist_ok=True)
    
    # Write configurations
    with open('.vscode/launch.json', 'w') as f:
        json.dump(launch_config, f, indent=4)
    
    with open('.vscode/tasks.json', 'w') as f:
        json.dump(tasks_config, f, indent=4)

if __name__ == '__main__':
    generate_vscode_configs()
