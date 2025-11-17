import os
import re

def extract_number(filename):
    """Extract the leading number from a filename for proper sorting."""
    match = re.match(r'^(\d+)\.', filename)
    if match:
        return int(match.group(1))
    return float('inf')  # Files without numbers go to the end

def generate_contents():
    """Generate contents.txt from code directory structure."""
    code_dir = "code"
    sections = {}
    
    # Scan code directory
    for folder_name in os.listdir(code_dir):
        folder_path = os.path.join(code_dir, folder_name)
        
        # Skip if not a directory
        if not os.path.isdir(folder_path):
            continue
        
        # Convert folder name to section title (replace - with space, capitalize words)
        section_title = folder_name.replace('-', ' ').replace('_', ' ').title()
        
        # Get all .cpp files (excluding __Test folders)
        files = []
        for filename in os.listdir(folder_path):
            file_path = os.path.join(folder_path, filename)
            
            # Only include .cpp files, not directories
            if os.path.isfile(file_path) and filename.endswith('.cpp'):
                files.append(filename)
        
        # Sort files by numeric prefix, then alphabetically
        files.sort(key=lambda f: (extract_number(f), f.lower()))
        
        # Store section if it has files
        if files:
            sections[folder_name] = {
                'title': section_title,
                'files': files
            }
    
    # Write contents.txt
    with open('contents.txt', 'w', encoding='utf-8') as f:
        f.write("# Auto-generated from code directory\n")
        f.write("# Section headings in square brackets\n")
        f.write("# Format: [filename]<TAB>[title]\n\n")
        
        # Sort sections alphabetically by folder name
        for folder_name in sorted(sections.keys()):
            section = sections[folder_name]
            f.write(f"[{section['title']}]\n")
            
            for filename in section['files']:
                # Remove .cpp extension for title
                title = filename.replace('.cpp', '')
                
                # Remove numeric prefixes like "1. ", "2. ", etc.
                import re
                title = re.sub(r'^\d+\.\s*', '', title)
                
                relative_path = f"{folder_name}/{filename}"
                f.write(f"{relative_path}\t{title}\n")
            
            f.write("\n")
        
        f.write("[Fin]\n")
    
    print(f"✅ Generated contents.txt with {len(sections)} sections")
    for folder_name in sorted(sections.keys()):
        print(f"   - {sections[folder_name]['title']}: {len(sections[folder_name]['files'])} files")

if __name__ == "__main__":
    generate_contents()
